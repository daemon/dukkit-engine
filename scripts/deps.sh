wget https://download.pytorch.org/libtorch/nightly/cpu/libtorch-shared-with-deps-latest.zip -O libs/libtorch.zip
unzip libs/libtorch.zip -d libs

git clone https://github.com/msgpack/msgpack-c libs/msgpack
cd libs/msgpack
cmake .
make
cd -
