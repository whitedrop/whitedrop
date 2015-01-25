'use strict'
exports.showMessageBox = function(content) {
	ShowMessage(content);
}

exports.on = function(id, callback) {
	if(['update', 'start', 'stop'].indexOf(id) !== -1) {
		console.log("on");
		WorldOn(id, callback);
	}
}