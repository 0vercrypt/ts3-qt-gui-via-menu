/*
 * TeamSpeak 3 demo plugin
 *
 * Copyright (c) 2008-2016 TeamSpeak Systems GmbH
 */

#ifdef _WIN32
#pragma warning (disable : 4100)
#include <Windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <basicdialog.h>
#include "teamspeak/public_errors.h"
#include "teamspeak/public_errors_rare.h"
#include "teamspeak/public_definitions.h"
#include "teamspeak/public_rare_definitions.h"
#include "teamspeak/clientlib_publicdefinitions.h"
#include "ts3_functions.h"
#include "plugin.h"

static struct TS3Functions ts3Functions;

#ifdef _WIN32
#define _strcpy(dest, destSize, src) strcpy_s(dest, destSize, src)
#define snprintf sprintf_s
#else
#define _strcpy(dest, destSize, src) { strncpy(dest, src, destSize-1); (dest)[destSize-1] = '\0'; }
#endif

#define PLUGIN_API_VERSION 21

#ifdef _WIN32
static int wcharToUtf8(const wchar_t* str, char** result) {
	int outlen = WideCharToMultiByte(CP_UTF8, 0, str, -1, 0, 0, 0, 0);
	*result = (char*)malloc(outlen);
	if(WideCharToMultiByte(CP_UTF8, 0, str, -1, *result, outlen, 0, 0) == 0) {
		*result = NULL;
		return -1;
	}
	return 0;
}
#endif

const char* ts3plugin_name() {
#ifdef _WIN32
	static char* result = NULL;
	if(!result) {
		const wchar_t* name = L"Basic TS3 QT GUI";
		if(wcharToUtf8(name, &result) == -1) {
			result = "Basic TS3 QT GUI";
		}
	}
	return result;
#else
	return "Basic TS3 QT GUI";
#endif
}

const char* ts3plugin_version() {
	return "1.0";
}

int ts3plugin_apiVersion() {
	return PLUGIN_API_VERSION;
}

const char* ts3plugin_author() {
	return "teamspeak-plugins.org";
}

const char* ts3plugin_description() {
	return "This plugin shows the use of a QT GUI as configuration window.";
}

void ts3plugin_setFunctionPointers(const struct TS3Functions funcs) {
	ts3Functions = funcs;
}

int ts3plugin_init() {
	return 0;
}

void ts3plugin_shutdown() {
}

int ts3plugin_offersConfigure() {
	return PLUGIN_OFFERS_CONFIGURE_QT_THREAD;
}

void ts3plugin_configure(void* handle, void* qParentWidget)
{
	Q_UNUSED(handle);

	basicdialog* config = new basicdialog((QWidget*)qParentWidget);
	config->setAttribute(Qt::WA_DeleteOnClose);
	config->exec();
}

const char* ts3plugin_commandKeyword() {
	return NULL;
}

int ts3plugin_processCommand(uint64 serverConnectionHandlerID, const char* command) {
	return 1;
}

void ts3plugin_freeMemory(void* data) {
	free(data);
}