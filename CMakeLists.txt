cmake_minimum_required(VERSION 3.10.0 FATAL_ERROR)
project(coinsample)

find_package(Coin REQUIRED)
find_package(SoQt REQUIRED)
find_package(
  Qt5 #5.12
  COMPONENTS
    Core
  REQUIRED
)
include_directories(${Coin_INCLUDE_DIRS} ${SoQt_INCLUDE_DIRS} ${Qt5Core_INCLUDE_DIRS})
set(LIBRARIES ${Coin_LIBRARIES} ${SoQt_LIBRARIES} ${Qt5Core_LIBRARIES})

MACRO (mksample inputfile)
  add_executable (${inputfile} ${inputfile}.cpp)
  target_link_libraries (${inputfile} ${LIBRARIES})
ENDMACRO(mksample)

mksample(autorotation)
mksample(Axis)
mksample(Curves)
mksample(examinerview)
mksample(faceset)
mksample(hello_cone)
mksample(Pipes)
mksample(Points)
mksample(Practice)
mksample(Source)
mksample(trackballmanipulator)
mksample(water)
mksample(wellbore) #copy in binfolder: data0.txt, data1.txt, colormap.txt.

