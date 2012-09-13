#include <iostream>

using namespace std;

#include "ImagemOpenCV.h"

#define ARG_PROGRAM   0
#define ARG_OUT_IMAGE 1
#define TOTAL_ARGS    2

#define VERBOSE(v)

#define FRACASSO 1
#define SUCESSO  0

#define NOME_DA_VIEWPORT "Camera2File-Image"

/* ARGSUSED */
int main( int argc, char **argv )
{
	// Testar quantidade de parametros
	if( argc != TOTAL_ARGS ) {
		cerr << "Erro na quantidade de parametros" << endl;
		return FRACASSO;
	}

	int res;
	res = cvInitSystem( argc, argv );
	res = cvNamedWindow( NOME_DA_VIEWPORT );
	cout << "res=" << res << endl;
	CvCapture *capture;
	capture = cvCreateCameraCapture( -1 );
	//capture = cvCaptureFromCAM( -1 );
	if( capture == NULL ) {
		cerr << "CAPTURE eh nulo. Abortando." << endl;
		return FRACASSO;
	}

	int i;
	i=0;
	IplImage* image;
	while( 1 ) {
		if( i%2 == 0 ) {
			cout << "-";
		} else {
			cout << "+";
		}
		i += 1;
		image = cvQueryFrame( capture );
		if( image == NULL ) {
			cerr << "A imagem obtida eh nula..." << endl;
			//return FRACASSO;
		} else {
			cvShowImage( NOME_DA_VIEWPORT, image );
		}
		cvWaitKey( 1000 );
	}

	cvReleaseCapture( &capture );
	cvDestroyWindow( NOME_DA_VIEWPORT );
	return SUCESSO;
}
