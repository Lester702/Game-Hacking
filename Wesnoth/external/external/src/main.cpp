#include <Windows.h>

int main(int argc, char** argv) {
	HWND wesnoth_window = FindWindow(NULL, L"The Battle for Wesnoth - 1.14.9");

	DWORD process_id = 0;
	GetWindowThreadProcessId(wesnoth_window, &process_id);

	HANDLE wesnoth_process = OpenProcess(PROCESS_ALL_ACCESS, true, process_id);

	auto address = 0x017EECB8;

	DWORD gold_value = 0;
	DWORD bytes_read = 0;
	ReadProcessMemory(wesnoth_process, (void*)0x017EECB8, &gold_value, 4, &bytes_read);


	ReadProcessMemory(wesnoth_process, (void*)0x017EED18, &gold_value, 4, &bytes_read);

	gold_value += 0xA90;
	ReadProcessMemory(wesnoth_process, (void*)gold_value, &gold_value, 4, &bytes_read);

	gold_value += 4;

	DWORD new_gold_value = 9999;
	DWORD bytes_written = 0;

	WriteProcessMemory(wesnoth_process, (void*)gold_value, &new_gold_value, 4, &bytes_written);
	return 0;
}