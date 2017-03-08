EMSCRIPTEN_SDK_PATH=~/emsdk/emsdk_portable

echo $EMSCRIPTEN_SDK_PATH

source $EMSCRIPTEN_SDK_PATH/emsdk_env.sh

FSEGT_PROJECT_NAME=BadRobots

FSE_FILES=`find FlameSteelEngine -name "*.cpp" | paste -s -d" "`
FSEGT_FILES=`find FlameSteelEngineGameToolkit -name "*.cpp" | paste -s -d" "`
FSEGT_PROJECT_FILES=`find $FSEGT_PROJECT_NAME -name "*.cpp" | paste -s -d" "`

FSEGT_PROJECT_COMPILE_FLAGS="-I. -o $FSEGT_PROJECT_NAME/$FSEGT_PROJECT_NAME.html --bind --use-preload-plugins --preload-file $FSEGT_PROJECT_NAME/data -s TOTAL_MEMORY=30728640 -O3 -ffast-math -std=c++11"

echo emcc $FSE_FILES $FSEGT_FILES $FSEGT_PROJECT_FILES $FSEGT_PROJECT_COMPILE_FLAGS

emcc $FSE_FILES $FSEGT_FILES $FSEGT_PROJECT_FILES $FSEGT_PROJECT_COMPILE_FLAGS