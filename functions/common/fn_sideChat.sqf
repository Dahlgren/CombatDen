/*
    Copyright (C) 2018 D. Ottavio

    You are free to adapt (i.e. modify, rework or update)
    and share (i.e. copy, distribute or transmit) this material
    under the Arma Public License Share Alike (APL-SA).

    You may obtain a copy of the License at:
    https://www.bohemia.net/community/licenses/arma-public-license-share-alike

    Description:

    Broadcast a message to all clients over sideChat.

    Parameter(s):

    0: STRING - Chat message to send,

    1: OBJECT - Unit sending message.

    Returns: true on success, false on error
*/
params ["_unit", "_message"];

_unit    = _this param [0, objNull, [objNull]];
_message = _this param [1, "", [""]];


if (isNull _unit) exitWith {
    ["unit parameter is null"] call BIS_fnc_error;
    false;
};

[_unit, _message] remoteExec ["sideChat"];

true;
