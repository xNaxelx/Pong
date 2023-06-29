set(CMAKE_TOOLCHAIN_FILE "C:/Program Files/vcpkg/scripts/buildsystems/vcpkg.cmake")

set(CMAKE_GENERATOR_PLATFORM "x64")
set(VCPKG_TARGET_TRIPLET "x64-windows")

cmake_minimum_required(VERSION 3.27.0)
project(pong)



set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

file(GLOB src source/*.cpp source/*.h)
add_executable(${PROJECT_NAME} ${WIN32_GUI} ${src})

#target_include_directories(${PROJECT_NAME} PRIVATE "source")

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main 
	SDL2::SDL2 
	SDL2_image::SDL2_image 
	SDL2_mixer::SDL2_mixer 
	SDL2_ttf::SDL2_ttf
	)
	
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
	
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/textures DESTINATION ${CMAKE_CURRENT_BINARY_DIR})	
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/sound DESTINATION ${CMAKE_CURRENT_BINARY_DIR})