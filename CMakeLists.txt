CMAKE_MINIMUM_REQUIRED( VERSION 2.6 )
PROJECT( CAMERA2FILE_IMAGE )
INCLUDE_DIRECTORIES( "C:/OpenCV2.2/include/opencv/"
                     "C:/OpenCV2.2/include/"
                     "C:/cmake/bibliotecas/auxCG/src/"
                     "C:/cmake/bibliotecas/auxMisc/src/"
                     "C:/cmake/opencv/bibliotecas/ImagemOOP/src/" )
LINK_DIRECTORIES( "C:/OpenCV2.2/lib/"
                  "C:/cmake/bibliotecas/auxCG/bin/Debug/"
                  "C:/cmake/bibliotecas/auxMisc/bin/Debug/"
                  "C:/cmake/opencv/bibliotecas/ImagemOOP/bin/Debug/" )
LINK_LIBRARIES( "opencv_highgui220.lib" "opencv_core220.lib" "auxMisc.lib" "auxCG.lib" "ImagemOOP.lib" )
SET( PROGRAM_SRCS main.cpp )
ADD_EXECUTABLE( camera2file_image ${PROGRAM_SRCS} )
