# Note: the module name is psycopg, not psycopg3
import psycopg
import getpass
import datetime

# Gather password from user
password = getpass.getpass("Please enter the master password: ")
job_title = input("Enter a job title")
# Generate connection string
connstr = "dbname=JobXite user=postgres" + " " + "password=" + password
# Connect to JobXiteTest DB using 'with' for context manager - connection automatically
# closed
with psycopg.connect(connstr) as conn:
    print(datetime.datetime.tzinfo)
    # Open a cursor to perform database operations
    with conn.cursor() as cur:

        # # Pass data to fill a query placeholders and let Psycopg perform
        # # the correct conversion (no SQL injections!)
        cur.execute(
            "INSERT INTO jobsummary (Job_title, job_date, job_images) VALUES (%s, %s, %s)",
            (job_title, datetime.datetime.now(), 
            ["/Users/devinlane/Library/Mobile Documents/com~apple~CloudDocs/JobXite" + 
            "/REPO/Backend/JXImages/RenderedImage.jpeg"]))
        dt = datetime.datetime.now(datetime.timezone.utc)
        # cur.execute('INSERT INTO job_summary (job_date) VALUES (%s)', (dt,))

        # Query the database and obtain data as Python objects.
        cur.execute("SELECT * FROM jobsummary")
        cur.fetchmany()
        # will return (1, 100, "abc'def")

        # You can use `cur.fetchmany()`, `cur.fetchall()` to return a list
        # of several records, or even iterate on the cursor
        for record in cur:
            print(record)

        # Make the changes to the database persistent
        conn.commit()
