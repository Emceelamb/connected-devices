# Postgres Example

An example RESTful API using Express.js, Node.js, and Postgresql. 

Deployed on [heroku](http://secure-headland-83484.herokuapp.com/ "link to live app")

### Routes
GET — / | displayHome()
GET — /users | getUsers()
GET — /users/:id | getUserById()
POST — users | createUser()
PUT — /users/:id | updateUser()
DELETE — /users/:id | deleteUser()

to send http request in the CLI use curl:

* `curl <url>  --data "name=Elaine&email=elaine@example.com"` - add's user
* `curl <url>/users/{id} -X PUT  -d "name=Elaine&email=elaine@example.com"` -updates user
* `curl <url>/users/{id} -X "DELETE" - deletes user
