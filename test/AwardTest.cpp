#include "gtest/gtest.h"
#include "../include/Awards.h"
#include "gmock/gmock.h"
#include <string>
#include <vector>
#include <iostream>
using ::testing::InSequence;

using awards::RankList;
using awards::AwardCeremonyActions;
using awards::performAwardCeremony;
using namespace std;


class stubRankList : public RankList {
	public:
		stubRankList() : names({"Person1","Person2","Person3", "Person4"}), index(0) {}

		string getNext() override {
			if (index >= names.size()) {
				return "";
				cout << index << endl;
			}
		return names[index++];
		}
	private:
		std::vector<std::string> names;
		int index;
};

class MockAwards : public AwardCeremonyActions {
	    public: 
	        MOCK_METHOD(void, playAnthem, (), (override));
		MOCK_METHOD(void, awardBronze, (string), (override));
		MOCK_METHOD(void, awardSilver, (string), (override));
		MOCK_METHOD(void, awardGold, (string), (override));
		MOCK_METHOD(void, turnOffTheLightsAndGoHome, (), (override));
};

TEST(AwardsTests, testingAwardsTest) {
	MockAwards awards;
	stubRankList recipients;
	{
	InSequence sequence;
	EXPECT_CALL(awards,playAnthem);
	EXPECT_CALL(awards, awardBronze("Person1"));
	EXPECT_CALL(awards, awardSilver("Person2"));
	EXPECT_CALL(awards, awardGold("Person3"));
	EXPECT_CALL(awards, turnOffTheLightsAndGoHome);
	}
	performAwardCeremony(recipients, awards);
}
