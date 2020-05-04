# prime_generator
Lazy generator of 'infinite' sequence of prime numbers in a range-v3 wrapper.

Not intended to be an example of 'best practice' and not an expert. The prime 
generator evolved from a 'normal' C++ class with an operator++. Will be looking
deeper...

Should be Windows/Linux compatible. Assumes for now vcpkg on both. Tested with
latest MSVC VS2019 16.6.0 Preview 5.0 and gcc 9.2.1.

On Windows just 'open folder' with VS and take it from there.

On Linux, for example,

~/src$ git clone http://github.com/epicyclism/prime_generator
...
~/src$ cd prime_generator
~/src/prime_generator$ mkdir build; cd build
~/src/prime_generator/build$ cmake -DCMAKE_TOOLCHAIN_FILE=/home/paul/vcpkg/scripts/buildsystems/vcpkg.cmake -DCMAKE_BUILD_TYPE=Release ..
...
~/src/prime_generator/build$ make

etc.

