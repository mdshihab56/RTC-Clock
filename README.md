# RTC-Clock
This Arduino program displays real-time clock (RTC) information on a 16x2 LCD screen using the DS1307 RTC module. It continuously updates the current time and date, formatted neatly, and ensures accurate tracking.

Initialization:

The LCD display is activated, and the RTC module is started.

If the RTC is not running, the program sets the time and date to the current compilation time using F(__DATE__), F(__TIME__).

Time and Date Retrieval:

The program fetches the current hour, minute, second, day, month, and year from the RTC module.

The time is displayed in 12-hour format, with AM/PM indication.

Leading zeros ensure proper formatting.

The date is shown in DD/MM/YYYY format.

LCD Display Update:

The LCD clears previous data and updates the time and date every 1 second (delay(1000)).

Pin Connections
Component	Arduino UNO Pin
RTC DS1307	SDA (A4), SCL (A5)
LCD Display	SDA (A4), SCL (A5)
