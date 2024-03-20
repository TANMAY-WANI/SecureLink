// Event listener for intercepting HTTP/HTTPS requests
chrome.webRequest.onBeforeRequest.addListener(
  function(details) {
      // Retrieve existing URLs from localStorage
      // Log the intercepted URL
      console.log("Intercepted request:", details);
      
      // Continue processing the request
      return { cancel:true };
  },
  { urls: ["<all_urls>"] },
  ["blocking"]
);
