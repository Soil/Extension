#include "common.h"
#include "objectdb.h"
#include "rapidjson-1.1.0/document.h"
#include "rapidjson-1.1.0/filereadstream.h"
#include "rapidjson-1.1.0/filewritestream.h"
#include "rapidjson-1.1.0/writer.h"
#include <exception>
#include <string>
#include <unistd.h>

using namespace Soil;

ObjectDB::ObjectDB(std::string worldName) {
    std::string fileName = worldName + ".sodb";
    this->json = ObjectDB::readFromFile(fileName);

    // Read parent databases
    if (this->json.HasMember("parents") && this->json["parents"].IsArray()) {
        for (auto& parent: json["parents"].GetArray()) {
            if (parent.IsString()) {
                auto pJson = ObjectDB::readFromFile(std::string(parent.GetString()) + ".sodb");

                // Merge into main db
                auto& allocator = this->json.GetAllocator();
                for (auto& member: pJson.GetObject()) {
                    this->json.AddMember(member.name, member.value, allocator);
                }
            }
        }

        this->json.RemoveMember("parents");
    }
}

rapidjson::Document ObjectDB::readFromFile(std::string fileName) {
    if (access(fileName.c_str(), R_OK)) {
        throw std::runtime_error("Object database " + fileName + " could not be found.");
    }

    FILE* file = std::fopen(fileName.c_str(), "r");
    char readBuffer[65536];
    rapidjson::FileReadStream fileStream(file, readBuffer, sizeof(readBuffer));

    rapidjson::Document json;
    json.ParseStream(fileStream);
    std::fclose(file);

    return json;
}

std::string ObjectDB::getObjectClassification(std::string modelInfo) {
    const char* c_modelInfo = modelInfo.c_str();
    if (this->json.HasMember(c_modelInfo) && this->json[c_modelInfo].IsObject()) {
        auto objectInfo = this->json[c_modelInfo].GetObject();
        if (objectInfo.HasMember("classification") && objectInfo["classification"].IsString()) {
            return objectInfo["classification"].GetString();
        } else {
            throw std::runtime_error("Broken object information for " + modelInfo + ".");
        }
    } else {
        return "unknown";
    }
}

void ObjectDB::dumpToFile(std::string fileName) {
    FILE* file = fopen(fileName.c_str(), "w");
    char writeBuffer[65536];
    rapidjson::FileWriteStream fileStream(file, writeBuffer, sizeof(writeBuffer));

    rapidjson::Writer<rapidjson::FileWriteStream> writer(fileStream);
    this->json.Accept(writer);
    fclose(file);
}
