console.log("Hello, world");

require('./bye.js')();

var engine = require('engine');
engine.showMessageBox('Welcome into Whitedrop Engine');

engine.on('start', function() {
	console.log('looks like engine started :)');
});