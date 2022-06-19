# get_data

`get_data` is how you retrieve the actual results (in a [`RegisterData`]) from the [`ResultHandle`] within the [`ExecutionData`] from the [`Success`] variant of an [`ExecutionResult`]. The register `name` provided to this function should match one that you provided to [`read_from`] (or `"ro"` if left at the default).

## Definition

```c
{{#include ../../../libqcs.h:get_data}}
```

## Safety

All inputs must be non-null. `name` must be a nul-terminated string. `handle` must come from the result of a non-error call to [`execute_on_qvm`] or [`execute_on_qpu`]. If there are no results matching the provided `name` then the return value will be `NULL`, make sure to check this return value.

## Arguments

1. `handle` is the `handle` attribute of [`ExecutionData`].
2. `name` is the name of a register you want the data from. It should correspond to a call to [`read_from`] (or the default of `"ro"`) and a Quil `DECLARE` instruction.

## Returns

A [`RegisterData`] if there was data for the requested register, or `NULL` if not.

## Example

```c
{{#include ../../../tests/integration_tests.c:read_from}}

{{#include ../../../tests/integration_tests.c:get_multiple}}
```

Our [`ExecutionResult`] named `result` is a [`Success`] variant, so we can access the [`ExecutionData`] via `result->success`. We can then call [`get_data`] with that [`ExecutionData`]'s `handle` attribute and the name of a register we want to retrieve.

[`ExecutionData`]: execution_data.md
[`ResultHandle`]: result_handle.md
[`Success`]: execution_result.md#success
[`RegisterData`]: register_data.md
[`ExecutionResult`]: execution_result.md
[`read_from`]: read_from.md
[`execute_on_qvm`]: execute_on_qvm.md
[`execute_on_qpu`]: execute_on_qpu.md
[`get_data`]: get_data.md
