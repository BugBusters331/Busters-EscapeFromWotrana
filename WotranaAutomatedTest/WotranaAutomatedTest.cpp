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
		TEST_METHOD(TestPlayerHealth) {
			Logger::WriteMessage(L"Testing ability to initialize player health and take damage\n");
			Player matt;
			Assert::AreEqual(100, matt.getPlayerHealth());
			matt.takeDamage(20);
			Assert::AreEqual(80, matt.getPlayerHealth());
			matt.takeDamage(100);
			Assert::AreEqual(-20, matt.getPlayerHealth());
			Assert::AreEqual(0, matt.getPlayerHealth(), L"Player health should not go below 0");
		}
	};
}
