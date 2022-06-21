## [0.2.0](https://github.com/rigetti/qcs-sdk-c/compare/v0.1.1...v0.2.0) (2022-06-18)

### Breaking Changes

Many interfaces have changed to align with the changes in `qcs-sdk-rust`.

1. The `Handle` variant of `ExecutionResult` has been renamed `Success` and is of a new type called `ExecutionData`.
2. The `ResultHandle` used with `get_data` is now the `handle` attribute on the new `ExecutionData` type. You can rename a line that was `result->handle` to `result->success.handle` to maintain the same behavior.
3. The old `ExecutionData` type has been renamed to `RegisterData`.

## [0.1.1](https://github.com/rigetti/qcs-sdk-c/compare/v0.1.0...v0.1.1) (2022-05-03)


### Chore

* auto update Cargo.lock ([b8f590a](https://github.com/rigetti/qcs-sdk-c/commit/b8f590a9248d929bc9a677f84d4961bee6733cac))
* explicitly use only remaining variant in match arm ([e598bb6](https://github.com/rigetti/qcs-sdk-c/commit/e598bb61a2499ba2f3c22366549267ef563ebc96))
* remove todo, open issue tracking type size (#12) ([935cc11](https://github.com/rigetti/qcs-sdk-c/commit/935cc1138fd1e40c09d0ad417f24f1745eb11ca5)), closes [#12](https://github.com/rigetti/qcs-sdk-c/issues/12)
* use cast method as per clippy remarks ([aedb07e](https://github.com/rigetti/qcs-sdk-c/commit/aedb07ebf761ea503a7842fb7563801613ac3391))

### Fix

* support ExecutionResult::I16 variant thru re-use of Byte ([6cc5a26](https://github.com/rigetti/qcs-sdk-c/commit/6cc5a26e23561c088e2b8c1b00fec9a52888d6fc))
* support ExecutionResult::I16 variant thru re-use of Byte (#11) ([b3c553c](https://github.com/rigetti/qcs-sdk-c/commit/b3c553c8480890c77ea72dc50cf90406c0785e91)), closes [#11](https://github.com/rigetti/qcs-sdk-c/issues/11)

## [0.1.0](https://github.com/rigetti/qcs-sdk-c/compare/v0.0.1...v0.1.0) (2021-12-08)


### Breaking

* Return pointers from `execute_on_qvm` and `execute_on_qpu` (#8) ([f7632fc](https://github.com/rigetti/qcs-sdk-c/commit/f7632fc6426ee23f9c99b8fe4fb66015029ac85a)), closes [#8](https://github.com/rigetti/qcs-sdk-c/issues/8)

### Chore

* Add a dry-run of semantic release to detect issues sooner. Bump SemRel to solve install issue (#10) ([82ada64](https://github.com/rigetti/qcs-sdk-c/commit/82ada649c584f5df6eb5d730f039dd612c258c08)), closes [#10](https://github.com/rigetti/qcs-sdk-c/issues/10)
* Fix cargo-deny by removing unneeded allowance. ([51d1afd](https://github.com/rigetti/qcs-sdk-c/commit/51d1afd2a96b68056316f6b2f05883d4d5f6ec7f))
* Upgrade Tokio to 1.14 to avoid security vulnerability. ([9ddb854](https://github.com/rigetti/qcs-sdk-c/commit/9ddb8541056d5b86955c0dfa0fec2f68ab4d58db))

## [0.0.1](https://github.com/rigetti/qcs-sdk-c/compare/v0.0.0...v0.0.1) (2021-10-19)


### Build

* Add CI checks ([052bf8d](https://github.com/rigetti/qcs-sdk-c/commit/052bf8d9027c67ff892799e8504d2a85c03c70f6))

### Chore

* Add semantic-release ([0b59742](https://github.com/rigetti/qcs-sdk-c/commit/0b5974210852081525c95763e1b438a77c84bc72))

### Docs

* Add book publish to GitHub Pages ([92c86ef](https://github.com/rigetti/qcs-sdk-c/commit/92c86efb1c66d055a440aa44abd6d32cc0d337d9))

### Upgrade

* Switch to released version of qcs ([d3da156](https://github.com/rigetti/qcs-sdk-c/commit/d3da156c61e9ed756d0614cca97d44bf44f39804))
