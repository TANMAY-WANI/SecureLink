chrome.webRequest.onBeforeRequest.addListener(
    function(details) {
        // Extract relevant data from intercepted request
        const url = details.url;
        const method = details.method;
        const headers = details.requestHeaders;
        
        // Send intercepted data to VPN server
        sendToVPNServer({ url, method, headers });
        
        // Continue processing the request
        return { cancel: false };
    },
    { urls: ["<all_urls>"], types: ["main_frame", "sub_frame"] },
    ["blocking", "requestHeaders"]
);