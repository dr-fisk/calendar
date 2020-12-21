<header>
  <h1> calendar</h1>
</header>
<h3>Ensure that DOW.dat and appts.csv is located within the same directory of the executable</h3>
  <body>
    <div>
      <body>
        <p>Usage: ./calendar.out appts.csv</p>
        <li>
              Search for a date
              Search for a subject
              Add appointment
              Get the appointment count
        </li>
      </body>
    </div
    The program works by reading in the appointments in appt.csv
    These appointments are then stored in a calendar object which contains a resizing array of days
    The days contain a set array of appointments
    Dayofweek returns the month, and day name of the date for the day
    For simplicity, every month contains 31 days
    DOW.dat is a little outdated, only containing dates up to 2017
</body>

