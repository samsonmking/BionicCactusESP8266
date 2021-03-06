#ifndef WIFI_FILE_H
#define WIFI_FILE_H

#include "persistance/FileHandler.hpp"
#include "constants/WifiConstants.hpp"
#include "ArduinoJson.h"
#include "FS.h"

using namespace Constants;

namespace Persistance {

    class WifiFileHandler : public FileHandler {
        public:
            WifiFileHandler();
            void save() override;
            void load() override;
            bool isConfigured();
            void setConfigured(bool configured);
            const char *getSSID();
            void setSSID(const char *ssid);
            const char *getPassword();
            void setPassword(const char *password);
            const char *getHostname();
            void setHostname(const char *hostname);
        private:
            const char *_filePath = "/wifi.json";
            static const size_t CONST_FILE_LENGTH = 400;
            bool _configured;
            char _ssid[100];
            char _password[100];
            char _hostname[100];
    };

}

#endif
