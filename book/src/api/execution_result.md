# `ExecutionResult`

An `ExecutionResult` is the struct you receive from a call to either [`execute_on_qvm`] or [`execute_on_qpu`]. This struct is implemented as a tagged union, describing the possible outcomes of program execution.

## SAFETY

**You must pass this struct to [`free_execution_result`] when you're done with it to avoid leaking the memory.**

**Any [`RegisterData`] which was retrieved from this result will be freed when this is called.**


## Definition

```c
{{#include ../../../libqcs.h:ExecutionResult}}
```

## Variants

There are multiple variants of `ExecutionResult`. The `tag` attribute determines which is in use via an enum:

```c
{{#include ../../../libqcs.h:ExecutionResult_Tag}}
```

The [`Error`] variant indicates that execution failed. The [`Success`] variant is populated in the case of a successful run, and contains an [`ExecutionData`].

### `Error`

If something goes wrong, `tag` will be `ExecutionResult_Error`, indicating it is the `Error` variant. This variant is a human-readable string of the error that occurred.

#### `Error` Example

Here, `result.error` is that string:

```c
{{#include ../../../tests/integration_tests.c:run}}

{{#include ../../../tests/integration_tests.c:errors}}
```

### `Success`

If there is not an error, `tag` will instead be `ExecutionResult_Success`. The `success` attribute is an [`ExecutionData`].

#### `Handle` Example

```c
{{#include ../../../tests/integration_tests.c:get_data}}
```


[`execute_on_qvm`]: execute_on_qvm.md
[`execute_on_qpu`]: execute_on_qpu.md
[`free_execution_result`]: free_execution_result.md
[`Error`]: #error
[`Success`]: #success
[`wrap_in_shots`]: wrap_in_shots.md
[`read_from`]: read_from.md
[`ResultHandle`]: result_handle.md
[`get_data`]: get_data.md
[`RegisterData`]: register_data.md
[`ExecutionData`]: execution_data.md
