# Memory leak detector

Just include *memory_leak.h* and call function *printMemoryLeak()* in the end of your program.

```C
#include <stdio.h>
#include <stdlib.h>
#include "memory_leak.h"
...
int main() {
...
	printMemoryLeak();
	return 0
}
```
