#include <iostream>
#include <map>
#include <Windows.h>


int main()
{
	// Declare and zero-initialize the map that will be used to hold the key scancodes

	std::map<char, UINT> keyToScanCode{};


	// Loop from character 'A' (65) to character 'Z' (90), attempt to map it into a scancode and then put it in the keyToScanCode map

	for (char key = 'A'; key <= 'Z'; ++key)
	{
		SHORT vk = VkKeyScan(key);

		if (!vk)
		{
			std::cerr << "Can't map key: " << key << " to a virtual key\n";
			continue;
		}

		int virtualKeyCode = vk & 0xFF;

		keyToScanCode[key] = MapVirtualKey(virtualKeyCode, MAPVK_VK_TO_VSC);
	}

	// key to try to find
	char key = 'A';


	// Check if the key exists in the map

	if (keyToScanCode.find(key) != keyToScanCode.end())
	{
		// If it exists then output the key and its scancode to the console

		std::cout << "The scancode of key: " << key << " is " << keyToScanCode[key] << '\n';
	}
	else
	{
		std::cout << "Could not find key\n";
	}

	return 0;
}