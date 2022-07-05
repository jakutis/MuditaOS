// Copyright (c) 2017-2022, Mudita Sp. z.o.o. All rights reserved.
// For licensing, see https://github.com/mudita/MuditaOS/LICENSE.md

#include "NotifyGUIBedtimeReminderAction.hpp"

#include <service-appmgr/include/service-appmgr/Constants.hpp>
#include <appmgr/messages/AlarmMessage.hpp>

namespace alarms
{
    NotifyGUIBedtimeReminderAction::NotifyGUIBedtimeReminderAction(sys::Service &service) : service{service}
    {}

    bool NotifyGUIBedtimeReminderAction::execute(uint32_t id)
    {
        return service.bus.sendUnicast(std::make_shared<BedtimeNotification>(id), service::name::appmgr);
    }

    bool NotifyGUIBedtimeReminderAction::turnOff()
    {
        return true;
    }
} // namespace alarms
