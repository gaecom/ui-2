/* 28 february 2014 */

/*
This includes all Objective-C runtime headers for convenience. It also creates wrappers around objc_msgSend() out of necessity.

cgo doesn't support calling variable argument list C functions, so objc_msgSend() cannot be called directly.

Furthermore, Objective-C selectors work by basically sending the arguments to objc_msgSend() verbatim across the wire. This basically means we're stuck making wrapper functions for every possible argument list. What fun!

The format should be self-explanatory.
*/

/* for some reason I now have to use an include guard after commit [master 9b4e30c] ("Started to build a single global delegate object; now to fix issues.") */
#ifndef _OBJC_DARWIN_H_
#define _OBJC_DARWIN_H_

#include <objc/message.h>
#include <objc/objc.h>
#include <objc/runtime.h>

#include <stdint.h>

struct xrect;		// TODO move that up here when finally getting rid of bleh_darwin.m

extern id toNSString(char *);
extern char *fromNSString(id);
extern void display(id);
extern struct xrect frame(id);
extern id makeScrollView(id);
extern void giveScrollViewBezelBorder(id);
extern id scrollViewContent(id);

// BEGIN OLD CODE

struct xrect {
	int64_t x;
	int64_t y;
	int64_t width;
	int64_t height;
};

struct xsize {
	int64_t width;
	int64_t height;
};

struct xpoint {
	int64_t x;
	int64_t y;
};

/* for uitask_darwin.go */
extern void initBleh();

#endif
