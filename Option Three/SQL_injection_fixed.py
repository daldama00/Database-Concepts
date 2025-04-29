import sqlite3

conn = sqlite3.connect(":memory:")
c = conn.cursor()
c.execute("CREATE TABLE users (username TEXT, password TEXT)")
c.execute("INSERT INTO users VALUES ('admin', 'pass')")

username = input("Username: ")
password = input("Password: ")

c.execute("SELECT * FROM users WHERE username=? AND password=?", (username, password))
print("Login success!" if c.fetchone() else "Login failed.")

