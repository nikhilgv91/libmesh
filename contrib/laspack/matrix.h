/****************************************************************************/
/*                                 matrix.h                                 */
/****************************************************************************/
/*                                                                          */
/* type MATRIX                                                              */
/*                                                                          */
/* Copyright (C) 1992-1996 Tomas Skalicky. All rights reserved.             */
/*                                                                          */
/****************************************************************************/
/*                                                                          */
/*        ANY USE OF THIS CODE CONSTITUTES ACCEPTANCE OF THE TERMS          */
/*              OF THE COPYRIGHT NOTICE (SEE FILE COPYRGHT.H)               */
/*                                                                          */
/****************************************************************************/

#ifndef MATRIX_H
#define MATRIX_H

#include "laspack_config.h"
#ifdef _LP_INCLUDED_FROM_CPLUSPLUS
extern "C" {
#endif

  
#include <stdlib.h>

#include "lastypes.h"
#include "elcmp.h"
#include "copyrght.h"

typedef struct {
    char *Name;
    size_t RowDim;
    size_t ClmDim;
    ElOrderType ElOrder;
    InstanceType Instance;
    int LockLevel;
    _LPDouble Multipl;
    _LPBoolean OwnData;
    size_t *Len;
    ElType **El;
    _LPBoolean *ElSorted;
} Matrix;

void M_Constr(Matrix *M, const char *Name, size_t RowDim, size_t ClmDim,
              ElOrderType ElOrder, InstanceType Instance, _LPBoolean OwnData);
void M_Destr(Matrix *M);
void M_SetName(Matrix *M, const char *Name);
const char *M_GetName(const Matrix *M);
size_t M_GetRowDim(const Matrix *M);
size_t M_GetClmDim(const Matrix *M);
ElOrderType M_GetElOrder(const Matrix *M);
void M_SetLen(Matrix *M, size_t RoC, size_t Len);
size_t M_GetLen(const Matrix *M, size_t RoC);
void M_SetEntry(Matrix *M, size_t RoC, size_t Entry, size_t Pos, _LPNumber Val);
size_t M_GetPos(const Matrix *M, size_t RoC, size_t Entry);
_LPNumber M_GetVal(const Matrix *M, size_t RoC, size_t Entry);
void M_AddVal(Matrix *M, size_t RoC, size_t Entry, _LPNumber Val);

/* macros for fast access */
#define     M__GetLen(PtrM, RoC)               (PtrM)->Len[RoC]
#define     M__SetEntry(PtrM, RoC, Entry, Pos_, Val_) { \
                (PtrM)->El[RoC][Entry].Pos = (Pos_); \
                (PtrM)->El[RoC][Entry].Val = (Val_); \
            }
#define     M__GetPos(PtrM, RoC, Entry)        (PtrM)->El[RoC][Entry].Pos
#define     M__GetVal(PtrM, RoC, Entry)        (PtrM)->El[RoC][Entry].Val
#define     M__AddVal(PtrM, RoC, Entry, Val_) { \
                (PtrM)->El[RoC][Entry].Val += (Val_); \
            }

_LPNumber M_GetEl(Matrix *M, size_t Row, size_t Clm);

void M_SortEl(Matrix *M);

void M_Lock(Matrix *M);
void M_Unlock(Matrix *M);

#ifdef _LP_INCLUDED_FROM_CPLUSPLUS
}
#endif

#endif /* MATRIX_H */
