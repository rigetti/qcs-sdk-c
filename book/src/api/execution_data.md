# ExecutionData

`ExecutionData` contains a [`ResultHandle`] to the [`RegisterData`] containing the results of the program, as well as some metadata about the execution itself. You get an `ExecutionData` from the [`Success`] variant of an [`ExecutionResult`].

## Definition

```c
{{#include ../../../libqcs.h:ExecutionData}}
```

## Safety

The memory for any `ExecutionData` will be freed when calling [`free_execution_result`] for the corresponding [`ExecutionResult`]. **Make sure not to free the [`ExecutionResult`] until after you're done with the data**.

## Attributes

1. `execution_duration_microseconds` is how long the program took to execute on the QPU. This is always 0 for QVM executions.
2. `handle` is the [`ResultHandle`] that can be passed to [`get_data`] to get [`RegisterData`] containing the results of the program.

[`get_data`]: get_data.md
[`free_execution_result`]: free_execution_result.md
[`ExecutionResult`]: execution_result.md
[`RegisterData`]: register_data.md
[`Success`]: execution_result.md#success
[`ResultHandle`]: result_handle.md
