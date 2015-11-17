cmake_minimum_required(VERSION 2.8)
project( Proyecto-PIC )
find_package( OpenCV REQUIRED )
add_library(Proyecto-PIC
  proy_lib.cpp
)
add_executable( vision_app main.cpp )
target_link_libraries( vision_app
 Proyecto-PIC
 ${OpenCV_LIBS} )

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


