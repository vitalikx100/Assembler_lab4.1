#include <iostream>

using namespace std;

int main()
{
	int A[5];
	int sum = 0;
	int sum_2 = 0;
	int b;
	cout << "Enter 5 elements of the array: ";
	for (int i = 0; i < 5; i++)
	{
		cin >> A[i];
	}
	cout << "Enter b: ";
	cin >> b;

	_asm
	{
		mov ecx, 5; <ecx> = 5
		lea esi, A; загружаем <esi> адрес начала массива A.
		mov ebx, b; <ebx> = b
		xor eax, eax; <eax> = 0

	loop_start:
		mov edx, [esi]; загружаем значение элемента массива A в <edx>
		cmp edx, 0; <edx> ? 0
		jle skip; если <edx> <= 0, то переход на метку skip

		cmp edx, ebx; <edx> ? <ebx>
		jl skip; если <edx> < <ebx> то переход на метку skip
		add eax, edx; <eax> = <eax> + <edx> 

	skip:
		add esi, 4;
		dec ecx; <ecx> -= 1
		jnz loop_start; перейти на метку loop_start, если значение флага ZF не равно 1
		mov sum, eax; помещаем в sum значение <eax>
	}

	cout << "asm: " << sum << endl;
	for (int i = 0; i < 5; i++)
	{
		if (b <= A[i] && A[i] > 0)
		{
			sum_2 += A[i];
		}
	}
	cout << "C++: " << sum_2 << endl;;

	return 0;
}