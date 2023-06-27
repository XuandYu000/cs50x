-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28
AND street = "Humphrey Street"; -- get the description of the theft

SELECT name, transcript FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28; -- get the transcriptions from the interviews

SELECT name
  FROM people
 WHERE license_plate IN
        (SELECT license_plate
           FROM bakery_security_logs
          WHERE year = 2021
            AND month = 7
            AND day = 28
            AND hour = 10
            AND minute > 15
            AND minute <= 25
            AND activity = "exit")
 ORDER BY name; --find the people who get out of the parking lot in the time frame

 SELECT name
  FROM people, bank_accounts
 WHERE people.id = bank_accounts.person_id
   AND account_number IN
       (SELECT account_number
          FROM atm_transactions
         WHERE year = 2021
           AND month = 7
           AND day = 28
           AND atm_location = "Leggett Street"
           AND transaction_type = "withdraw")
 ORDER BY name; -- select the people who withdraw money on the street

SELECT name
  FROM people
 WHERE passport_number IN
        (SELECT passport_number
           FROM passengers
          WHERE flight_id IN
                (SELECT id
                   FROM flights
                  WHERE year = 2021
                    AND month = 7
                    AND day = 29
                    AND origin_airport_id IN
                        (SELECT id
                           FROM airports
                          WHERE city = "Fiftyville")
                  ORDER BY hour
                  LIMIT 1))
 ORDER BY name;-- the people who buy the earlist flight

SELECT name
  FROM people
 WHERE phone_number IN
       (SELECT caller
          FROM phone_calls
         WHERE year = 2021
           AND month = 7
           AND day = 28
           AND duration < 60)
 ORDER BY name;--找到一天打电话时间小于60s的人


