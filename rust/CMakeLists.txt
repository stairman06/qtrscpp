find_package(Corrosion REQUIRED)

corrosion_import_crate(MANIFEST_PATH Cargo.toml)
add_custom_target(libh ALL
  COMMAND echo "Creating Rust header..."
  COMMAND cbindgen --crate library-rs --output ${PROJECT_BINARY_DIR}/rustlib.h
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)