var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);
var port = process.env.PORT || 3000;

app.get('/', function(req, res){
	res.sendFile(__dirname + '/index.html');
});

io.on('connection', function(socket){
	var addedUser = false; 

	socket.on('chat message', function(msg){
		io.emit('chat message', msg);
	});

	socket.on('add user request', function(msg){
		socket.emit('login', {
	    	numUsers: numUsers
	    });
	});

	socket.on('add user', function (username) {
	    // we store the username in the socket session for this client
	    socket.username = username;
	    // add the client's username to the global list
	    usernames[username] = username;
	    ++numUsers;
	    addedUser = true;
	    

	    // echo globally (all clients) that a person has connected
	    socket.broadcast.emit('user joined', {
	    	username: socket.username,
	    	numUsers: numUsers
	    });
	});


	// when the user disconnects.. perform this
  socket.on('disconnect', function () {
    // remove the username from global usernames list
    if (addedUser) {
      delete usernames[socket.username];
      --numUsers;

      // echo globally that this client has left
      socket.broadcast.emit('user left', {
        username: socket.username,
        numUsers: numUsers
      });
    }
  });
});

http.listen(port, function () {
	console.log('Server listening at port %d', port);
});

// usernames which are currently connected to the chat
var usernames = {};
var numUsers = 0;