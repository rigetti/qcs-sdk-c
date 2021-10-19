# qcs-sdk-c

C bindings to [the Rust QCS SDK] to enable pyQuil-like features from C and C-compatible languages.

## Setup

This library is implemented in Rust, so the first thing you need is [rustup]. The default, stable toolchain will work just fine.

Next, because this library relies on [ØMQ], you'll need [`cmake`] installed:

- macOS [Homebrew] : `brew install cmake`
- Windows [Chocolatey]: `choco install cmake`
- Debian: `apt install cmake`

Finally, this project uses [cargo-make] in order to orchestrate build tasks, so install that using `cargo install cargo-make`.


## Development

1. Run `makers` (no args, default flow) to build and run tests.
2. `makers lint` does linting.
3. `makers release-flow` will do a release build of the C-SDK and spit out a `.dylib` file in the current directory.
4. `makers detect-leaks` will run the tests with clang arguments that will attempt to detect memory issues.

## Documentation

This library is documented using [mdBook]. The hosted version can be found [GitHub Pages]. You can use `makers book` to build it or `makers serve-book` to run a local webserver which will watch for _some_ changes.

[rustup]: https://rustup.rs/
[ØMQ]: https://zeromq.org/
[cmake]: https://cmake.org/
[homebrew]: https://brew.sh/
[Chocolatey]: https://chocolatey.org/
[cargo-make]: https://sagiegurari.github.io/cargo-make/
[mdbook]: https://rust-lang.github.io/mdBook/
[the Rust QCS SDK]: https://github.com/rigetti/qcs-sdk-rust
[GitHub Pages]: https://rigetti.github.io/qcs-sdk-c/
