cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
find_package( OpenCV REQUIRED )
add_library(DisplayImage
  movimiento.cpp
)
add_executable( DisplayImage_node prueba.cpp )
target_link_libraries( DisplayImage_node ${OpenCV_LIBS} )

# En caso de querer crear varios ejecutables al mismo tiempo (retirar el if(0) y endif(0))
if(0)
file (GLOB_RECURSE SRC_FILES *.cpp)

foreach (src_file ${SRC_FILES})
	MESSAGE (STATUS "Processing file: ${src_file}")
	# Executable name = source file name without extension
	get_filename_component (exec_name ${src_file} NAME_WE)
	# Add executable
	add_executable (${exec_name} ${src_file})
	MESSAGE (STATUS "Exec file: ${exec_name}")
	# Link OpenCV libraries to executable
	target_link_libraries (${exec_name} ${OpenCV_LIBS})
endforeach (src_file ${SRC_FILES})
endif(0)


