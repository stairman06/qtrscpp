#[no_mangle]
pub extern "C" fn hello_rust(cb: extern "C" fn()) {
  println!("Hello from Rust!");
  cb();
}
