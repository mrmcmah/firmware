#pragma once
#include "SinglePortModule.h"
#ifdef ARCH_ESP32
#include "sleep.h"
#endif

class DetectionSensorModule : public SinglePortModule, private concurrency::OSThread
{
  public:
    DetectionSensorModule() : SinglePortModule("detection", meshtastic_PortNum_DETECTION_SENSOR_APP), OSThread("DetectionSensor")
    {
    }

  protected:
    virtual int32_t runOnce() override;

  private:
    bool firstTime = true;
    uint32_t lastSentToMesh = 0;
    bool wasDetected = false;
    void sendDetectionMessage();
    void sendCurrentStateMessage(bool state);
    bool hasDetectionEvent();

#ifdef ARCH_ESP32
    // Wildfire Mesh: the monitor pin wakes the CPU from light sleep, so a short press isn't missed
    bool wokeByDetection = false;
    int beforeLightSleep(void *unused);
    int afterLightSleep(esp_sleep_wakeup_cause_t cause);
    CallbackObserver<DetectionSensorModule, void *> lsObserver =
        CallbackObserver<DetectionSensorModule, void *>(this, &DetectionSensorModule::beforeLightSleep);
    CallbackObserver<DetectionSensorModule, esp_sleep_wakeup_cause_t> lsEndObserver =
        CallbackObserver<DetectionSensorModule, esp_sleep_wakeup_cause_t>(this, &DetectionSensorModule::afterLightSleep);
#endif
};

extern DetectionSensorModule *detectionSensorModule;
