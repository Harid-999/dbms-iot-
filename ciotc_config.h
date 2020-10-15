// This file contains your configuration used to connect to Cloud IoT Core

// Wifi newtork details.
const char *ssid = "your-ssid";
const char *password = "password";

// Cloud iot details.
const char *project_id = "your-project_id";
const char *location = "asia-east1";
const char *registry_id = "your-registry_id";
const char *device_id = "your-device_id";

const char *private_key_str =
    "your-private_key_str"
    "your-private_key_str"
    "your-private_key_str";

const int jwt_exp_secs = 3600; // Maximum 24H (3600*24)

const char *root_cert =
"-----BEGIN CERTIFICATE-----\n"
"your-root_cert\n"
"your-root_cert\n"
"your-root_cert\n"
"-----END CERTIFICATE-----\n";
