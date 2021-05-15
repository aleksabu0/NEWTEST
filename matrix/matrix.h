/**
 * @file matrix.h
 * @brief biblioteka za rad sa matricama
 * @author ABYU
 * @date 12.05.2021.
 */
#ifndef MATRIX_H_
#define MATRIX_H_
#define DIM 3
#include <stdint.h>

/**
 * Funckija proverava jednakost matrica
 * @param kvadratna matrica a, kvadratna matrica b
 * @return 0 ili 1
 */
int8_t CheckEquality(int8_t a[DIM][DIM], int8_t b[DIM][DIM]);

/**
 * Funckija sabira matrice
 * @param kvadratna matrica a, kvadratna matrica b, matrica c gde je rezultat
 * @return nema
 */
void Add(int8_t a[DIM][DIM], int8_t b[DIM][DIM], int8_t c[DIM][DIM]);

/**
 * Funckija oduzima matrice
 * @param kvadratna matrica a, kvadratna matrica b, matrica c gde je rezultat
 * @return nema
 */
void Subtract(int8_t a[DIM][DIM], int8_t b[DIM][DIM], int8_t c[DIM][DIM]);

/**
 * Funckija mnozi matrice
 * @param kvadratna matrica a, kvadratna matrica b, matrica c gde je rezultat
 * @return nema
 */
void Multiply(int8_t a[DIM][DIM], int8_t b[DIM][DIM], int8_t c[DIM][DIM]);

/**
 * Funckija transponuje matrice
 * @param kvadratna matrica a, kvadratna transponovana matrica a_tran
 * @return nema
 */
void Transpose(int8_t a[DIM][DIM], int8_t a_tran[DIM][DIM]);

/**
 * Funckija racuna zbir elemenata glavne dijagonale matrice
 * @param kvadratna matrica a
 * @return suma elemenata
 */
int8_t SumMainDiagonal(int8_t a[DIM][DIM]);

/**
 * Funckija racuna zbir elemenata sporedne dijagonale matrice
 * @param kvadratna matrica a
 * @return suma elemenata
 */
int8_t SumMinorDiagonal(int8_t a[DIM][DIM]);


#endif /* MATRIX_H_ */
