#ifndef _BF_VM_H_
#define _BF_VM_H_

#include <stdlib.h>
#include <stdint.h>

#define MAX_CELLS 30000

typedef int cell_t;
typedef int *jit_label_t;

struct _bf_vm_loop {
    /* FIXME: append JIT-specific members */
    jit_label_t start_label;
    jit_label_t end_label;
    struct _bf_vm_loop *parent;
};

typedef struct _bf_vm_loop bf_vm_loop;
typedef char *jit_context_t;
typedef int *jit_value_t;
typedef void *jit_function_t;

typedef struct {
    cell_t *data;
    bf_vm_loop *current_loop;

    /* FIXME: append JIT-specific members */
    jit_context_t jit_context;
    jit_value_t data_ptr;
    jit_function_t jit_function;
} bf_vm;

bf_vm *bf_vm_create();
int bf_vm_init(bf_vm *vm);
void bf_vm_free(bf_vm *vm);
int bf_vm_run(bf_vm *vm);
jit_context_t jit_context_create();

#endif
