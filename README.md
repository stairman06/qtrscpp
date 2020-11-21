# QtRsCpp

Have you ever wanted to use Qt and Rust together? Well now you can, sort of, using the joy of CMake.

This is just a template that uses CMake to build a C++ Qt QML application that communicates with a core library written in Rust. It has decent support for asynchronous functions in Rust (through callbacks/C++ Function Pointers), and has support for QML.

## Why?
I wanted to write an application in Rust, but the current Rust GUI libraries are not yet advanced enough. Rust bindings for Qt are annoying to work with and incomplete. `web-view` was also not ideal, as asynchronous and multithreaded tasks with it are a pain.

## Requirements
- [CMake >=3.18](https://cmake.org/)
- [Rust and Cargo](https://rustup.rs/)
- [Qt5](https://www.qt.io/)
  - Tip: Want to bypass the Qt installer's stupid account requirement? Use an offline installer! [You can download them here](https://download.qt.io/archive/qt/5.14/). Make sure to turn off your PCs internet before running the installer, or else you'll be forced to log in with a Qt account.
  - Linux users: just install it from your distro's repos :)
  - Make sure it's in your CMAKE_PREFIX_PATH
- [Corrosion](https://github.com/AndrewGaspar/corrosion) for building the Rust library
  - Make sure it's in your CMAKE_PREFIX_PATH
- [cbindgen](https://github.com/eqrion/cbindgen) installed to your system
  - Just run `cargo install --force cbindgen`, assuming you already have Cargo installed.

## Building
Building is easy.

### Windows
Generate CMake scripts:
```
mkdir build
cd build
cmake ..
```
Build the application:
```
cmake --build build
```
The program will reside at `build/gui/Debug/gui.exe`.

### Linux
TODO

### Mac
TODO

## Future Possibilities
- Using [cxx](https://github.com/dtolnay/cxx) for better C++ FFI
  - CXX is a fantastic tool, but it currently lacks passing a C++ function pointer to Rust. I needed this for asynchronous tasks performed in the Rust library, so I ended up using [cbindgen](https://github.com/eqrion/cbindgen) instead
  - Once CXX gains function pointers and better async support, I will likely move to it
- Multiplatform support
  - This is all currently designed for Win32. I will need to make it more platform-agnostic (e.g. using `macdeployqt`, `linuxdeployqt`)