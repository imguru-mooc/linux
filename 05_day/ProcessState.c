#if 1
#include <stdio.h>
class ProcessState
{
	private:
		ProcessState()
		{
			printf("binder_open()\n");
		}

	public:
		static ProcessState *process;
		static ProcessState *self()
		{
			if( process == 0 )
			{
				process = new ProcessState;
			}
			return process;
		}
};

ProcessState * ProcessState::process = 0;

int main()
{
	ProcessState *p1 = ProcessState::self();
	ProcessState *p2 = ProcessState::self();
	ProcessState *p3 = ProcessState::self();
	ProcessState *p4 = ProcessState::self();
	return 0;
}
#endif
#if 0
#include <stdio.h>
class ProcessState
{
	private:
		ProcessState()
		{
			printf("binder_open()\n");
		}

	public:
		static ProcessState *self()
		{
			return new ProcessState;
		}
};

int main()
{
	ProcessState *p1 = ProcessState::self();
	ProcessState *p2 = ProcessState::self();
	return 0;
}
#endif

#if 0
#include <stdio.h>
class ProcessState
{
	public:
		ProcessState()
		{
			printf("binder_open()\n");
		}
};

int main()
{
	ProcessState p1;
	ProcessState p2;
	return 0;
}
#endif
