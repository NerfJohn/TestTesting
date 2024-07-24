/*
 * RetErr_e.h
 *
 *  Created on: Jul 24, 2024
 *      Author: John
 */

#ifndef SRC_DOMAINLAYER_RETERR_E_H_
#define SRC_DOMAINLAYER_RETERR_E_H_

// Generic return code to denote error (for defensive programming).
typedef enum {
    RET_GOOD = 0, // explicitly "0" to fail any if() checks
    RET_FAIL = 1  // explicitly non-zero to trigger failure checks
} RetErr_e;

#endif /* SRC_DOMAINLAYER_RETERR_E_H_ */
