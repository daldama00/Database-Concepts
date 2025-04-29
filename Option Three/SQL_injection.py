import sqlite3
import sys

conn = sqlite3.connect(":memory:")
c = conn.cursor()
c.execute("CREATE TABLE users (username TEXT, password TEXT)")
c.execute("INSERT INTO users VALUES ('admin', 'pass')")

username = input("Username: ")
password = input("Password: ")

query = f"SELECT * FROM users WHERE username='{username}' AND password='{password}'"
print(f"Running query: {query}")
c.execute(query)
print("Login success!" if c.fetchone() else "Login failed.")

