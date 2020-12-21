<!DOCTYPE html>
<html>
  <header>
    <h1> Calendar</h1>
    <h3>Ensure that DOW.dat and appts.csv is located within the same directory of the executable</h3>
  </header>
   <body>
     <div>
        <p>Usage: ./calendar.out appts.csv</p>
        <p>There are 5 options that are printed to the command line</p>
        <li>Done</li>
        <li>Search for a date</li>
        <li>Search for a subject</li>
        <li>Add appointment</li>
        <li>Get the appointment count</li>
      </div>
      <div>
        <h4>Use make to compile the program</h4>
        <p>
          The program reads appointments in the appts.csv file.
          These appointments are then stored in a calendar object which contains a resizing array of days.
          The days contain a templated linked list of appointments.
          Dayofweek returns the month (ex. January), day name (ex. Monday), and year for a given date (ex. 10/1/2012.)
          For simplicity, every month contains 31 days.
          DOW.dat is a little outdated, only containing dates up to 2017.
          This program makes use of OOP, polymorphism, and templating. There are a couple features planned for the future
          like writing back to appts.csv when a user creates a new appointment, removing an appointment, etc.
        </p>
      </div>
  </body>
</html>
