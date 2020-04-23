#include "syscall.h"

int
main()
{
    SpaceId newProc;
    OpenFileId input = ConsoleInput;
    OpenFileId output = ConsoleOutput;
    char prompt[2], ch, buffer[60];
    int i;

    prompt[0] = '>';
    prompt[1] = '>';

    while( 1 )
    {
	Write(prompt, 2, output);

	Read(&buffer, 60, input); 

	newProc = Exec(buffer);
	Join(newProc);
	
    }
}

