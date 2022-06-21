/* Warning, this file is autogenerated by cbindgen. Don't modify this manually except to replace anchors. */

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>


/**
 * Holds the state required to execute a program.
 * Intentionally opaque to C.
 */
// ANCHOR: Executable
typedef struct Executable Executable;
// ANCHOR_END: Executable

/**
 * The return value of [`execute_on_qvm`] or [`execute_on_qpu`].
 *
 * Holds result data internally, intentionally opaque to C since it uses a map internally
 */
// ANCHOR: ResultHandle
typedef struct ResultHandle ResultHandle;
// ANCHOR_END: ResultHandle

// ANCHOR: ExecutionData
typedef struct ExecutionData {
    unsigned long execution_duration_microseconds;
    struct ResultHandle *handle;
} ExecutionData;
// ANCHOR_END: ExecutionData

// ANCHOR: ExecutionResult_Tag
typedef enum ExecutionResult_Tag {
    ExecutionResult_Success,
    ExecutionResult_Error,
} ExecutionResult_Tag;
// ANCHOR_END: ExecutionResult_Tag

// ANCHOR: ExecutionResult
typedef struct ExecutionResult {
    ExecutionResult_Tag tag;
    union {
        struct {
            struct ExecutionData success;
        };
        struct {
            char *error;
        };
    };
} ExecutionResult;
// ANCHOR_END: ExecutionResult

// ANCHOR: DataType_Tag
typedef enum DataType_Tag {
    DataType_Byte,
    DataType_Real,
} DataType_Tag;
// ANCHOR_END: DataType_Tag

// ANCHOR: DataType
typedef struct DataType {
    DataType_Tag tag;
    union {
        struct {
            char **byte;
        };
        struct {
            double **real;
        };
    };
} DataType;
// ANCHOR_END: DataType

/**
 * The contents of a single register within a [`ResultHandle`], fetched with [`get_data`]
 */
// ANCHOR: RegisterData
typedef struct RegisterData {
    unsigned short number_of_shots;
    unsigned short shot_length;
    struct DataType data;
} RegisterData;
// ANCHOR_END: RegisterData

/**
 * Constructs an [`Executable`] and returns a raw pointer to it.
 *
 * # Safety
 *
 * 1. The result of this function must later be passed to [`free_executable`] or the memory will be leaked.
 * 2. `quil` must be a valid, non-NULL, nul-terminated string which must remain constant and valid until [`free_executable`] is called.
 *
 * # Arguments
 *
 * 1. `quil`: A string containing a valid Quil program
 *
 * # Errors
 *
 * If an error occurs in this function, NULL will be returned.
 *
 * 1. The contents of `quil` were not valid UTF-8. In this case, the returned value will be NULL.
 */
// ANCHOR: executable_from_quil
struct Executable *executable_from_quil(char *quil);
// ANCHOR_END: executable_from_quil

/**
 * Run an executable (created by [`crate::executable_from_quil`]) on a real QPU.
 *
 * # Safety
 *
 * 1. You must provide the return value from this function to [`crate::free_execution_result`]
 *     once you're done with it.
 * 2. The input `qpu_id` must be valid, nul-terminated, non-null strings which remain constant for
 *     the duration of this function.
 * 3. `executable` must be the non-NULL result of a call to [`crate::executable_from_quil`] and
 *     must not be freed during the execution of this function.
 *
 * # Usage
 *
 * In order to execute, you must have an active reservation for the QPU you're targeting.
 *
 * ## Configuration
 *
 * Valid settings and secrets must be set either in ~/.qcs or by setting the OS environment
 * variables `QCS_SECRETS_FILE_PATH` and `QCS_SETTINGS_FILE_PATH` for secrets and settings
 * respectively. `QCS_PROFILE_NAME` can also be used to choose a different profile in those
 * configuration files.
 *
 * # Arguments
 *
 * 1. `executable`: the result of a call to [`crate::executable_from_quil`]
 * 2. `qpu_id`: the ID of the QPU to run on (e.g. `"Aspen-9"`)
 *
 * # Errors
 *
 * This program will return a [`crate::ExecutionResult::Error`] if an error occurs.
 */
// ANCHOR: execute_on_qpu
struct ExecutionResult *execute_on_qpu(struct Executable *executable, char *qpu_id);
// ANCHOR_END: execute_on_qpu

/**
 * Given a Quil program as a string, run that program on a local QVM.
 *
 * # Safety
 *
 * 1. You must provide the return value from this function to [`crate::free_execution_result`] once
 *    you're done with it.
 * 2. `executable` must be the valid, non-NULL result of [`crate::executable_from_quil`]
 *
 * # Usage
 *
 * In order to execute, QVM must be running at <http://localhost:5000>.
 *
 * # Arguments
 *
 * 1. `program`: A string containing a valid Quil program. Any measurements that you'd like
 * to get back out must be in a register matching `register_name`. For example, if you have
 * `MEASURE 0 ro[0]` then `register_name` should be `"ro"`.
 * 2. `num_shots`: the number of times you'd like to run the program.
 * 3. `register_name`: the name of the register in the `program` that is being measured to.
 *
 * # Errors
 *
 * This program will return a [`crate::ExecutionResult::Error`] if an error occurs.
 */
// ANCHOR: execute_on_qvm
struct ExecutionResult *execute_on_qvm(struct Executable *executable);
// ANCHOR_END: execute_on_qvm

/**
 * Free an [`Executable`]
 *
 * # Safety
 *
 * 1. Only call this with the non-null output of [`executable_from_quil`].
 * 2. Only call this function once per executable if you don't want to double-free your memory.
 */
// ANCHOR: free_executable
void free_executable(struct Executable *executable);
// ANCHOR_END: free_executable

/**
 * Frees the memory of an [`ExecutionResult`] as allocated by [`execute_on_qvm`] or [`execute_on_qpu`]
 *
 * # Safety
 * This function should only be called with the result of one of the above functions.
 */
// ANCHOR: free_execution_result
void free_execution_result(struct ExecutionResult *result);
// ANCHOR_END: free_execution_result

/**
 * Return a pointer to the [`ExecutionResult`] for a specific register or null if the register is not found.
 *
 * # Safety
 * All inputs must be non-null. `name` must be a nul-terminated string. `handle` must be the result
 * of a non-error call to [`execute_on_qvm`] or [`execute_on_qpu`]
 */
// ANCHOR: get_data
const struct RegisterData *get_data(const struct ResultHandle *handle, const char *name);
// ANCHOR_END: get_data

/**
 * Set the memory location to read out of.
 *
 * # Safety
 *
 * 1. `executable` must be the result of [`executable_from_quil`]
 * 2. `register` must be a valid, non-NULL, nul-terminated string. It must also live until `executable`
 *     is freed.
 *
 * # Arguments
 *
 * 1. `executable`: The [`Executable`] to set the parameter on.
 * 2. `register`: The name of the memory region to read out of. Must match a Quil `DECLARE`
 *     statement exactly.
 */
// ANCHOR: read_from
void read_from(struct Executable *executable, char *name);
// ANCHOR_END: read_from

/**
 * Set the value of a parameter for parametric execution.
 *
 * # Safety
 *
 * 1. `executable` must be the non-NULL result of [`executable_from_quil`]
 * 2. `name` must be a valid, non-NULL, nul-terminated string. It must also live until `executable`
 *     is freed.
 *
 * # Arguments
 *
 * 1. `executable`: The [`Executable`] to set the parameter on.
 * 2. `name`: The name of the memory region to set, must match a Quil `DECLARE` statement exactly.
 * 3. `index`: The index into the named memory region to set.
 * 3. `value`: The value to set the parameter to.
 *
 * # Errors
 *
 * If an error occurs, the return value of this function will be non-null
 */
// ANCHOR: set_param
void set_param(struct Executable *executable, char *name, unsigned int index, double value);
// ANCHOR_END: set_param

/**
 * Set the program to run multiple times on the QPU.
 *
 * # Safety
 *
 * 1. `executable` must be the result of [`executable_from_quil`]
 *
 * # Arguments
 *
 * 1. `executable`: The [`Executable`] to set the parameter on.
 * 2. `shots`: The number of times to run the program for each execution.
 */
// ANCHOR: wrap_in_shots
void wrap_in_shots(struct Executable *executable, unsigned short shots);
// ANCHOR_END: wrap_in_shots
