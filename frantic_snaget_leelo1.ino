int SensorPIR = 2;
const int soilMoistureSensor = 3;
bool curr_State = false;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(SensorPIR, INPUT);
  pinMode(soilMoistureSensor, INPUT);

  attachInterrupt(digitalPinToInterrupt(SensorPIR), swap, CHANGE);
  attachInterrupt(digitalPinToInterrupt(soilMoistureSensor), soil_moist, RISING);
}

void loop()
{
  delay(1000);
}

void swap()
{
  curr_State = !curr_State;
  digitalWrite(LED_BUILTIN, curr_State);
  Serial.println("Motion Interrupt");
}

void soil_moist()
{
  Serial.println("Soil Moisture Interrupt");
}