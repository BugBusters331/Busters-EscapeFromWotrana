#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../Busters-EscapeFromWotrana/Player.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace WotranaAutomatedTest
{
	TEST_CLASS(WotranaAutomatedTest)
	{
	public:
		
		TEST_METHOD(HelloAutoTest) {
			Logger::WriteMessage("Hello from first test case\n");
		}

		TEST_METHOD(TestPlayerName) {
			Logger::WriteMessage(L"Testing ability to set and get player name\n");
			string playerName = "Christine Aguilera";
			Player chrissy;
			chrissy.setPlayerName(playerName);
			Assert::AreEqual(playerName, chrissy.getPlayerName());
		}
	};
}
