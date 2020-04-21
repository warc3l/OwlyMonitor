#ifndef _DEVICE_DATA_HPP
#define _DEVICE_DATA_HPP

class DeviceData {
    private:
        float _value;
        unsigned int _uid;
    public:
        DeviceData() = default;

        float getValue() {
            return _value;
        }
        unsigned int getUID() {
            return _uid;
        }

        void setValue(float p_value) {
            _value = p_value;
        }
        void setUID(unsigned int p_uid) {
            _uid = p_uid;
        }

};

#endif