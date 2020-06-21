#pragma once

typedef struct {

	unsigned long dwAddress;
	unsigned char pBytes[32];

} MDump;

bool MCheckDump(void);