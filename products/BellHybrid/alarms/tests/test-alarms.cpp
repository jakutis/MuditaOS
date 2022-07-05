// Copyright (c) 2017-2022, Mudita Sp. z.o.o. All rights reserved.
// For licensing, see https://github.com/mudita/MuditaOS/LICENSE.md

#include <gtest/gtest.h>

#include "BellAlarmHandler.hpp"

class MockedService : public sys::Service
{
  public:
    MockedService(const std::string &name) : sys::Service(name)
    {}

    sys::ReturnCodes InitHandler() override
    {
        return sys::ReturnCodes::Success;
    }
    sys::ReturnCodes DeinitHandler() override
    {
        return sys::ReturnCodes::Success;
    }
    sys::ReturnCodes SwitchPowerModeHandler(const sys::ServicePowerMode mode) override
    {
        return sys::ReturnCodes::Success;
    }
    sys::MessagePointer DataReceivedHandler(sys::DataMessage *req, sys::ResponseMessage *resp) override
    {
        return std::make_shared<sys::ResponseMessage>();
    };
};

TEST(basic, test1)
{
    auto service                = MockedService{"ala"};
    auto bedtimeReminderHandler = alarms::BedtimeReminderHandler{&service};
    std::string musicTone{"mTone"};
    std::string rrule{"rrule"};
    auto alarmEventRecord = AlarmEventRecord{12, AlarmTime{0h, 0min}, musicTone, true, 123, rrule};
    bedtimeReminderHandler.handle(alarmEventRecord);

    EXPECT_TRUE(false);
}
