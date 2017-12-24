(function() {
  $(document).ready(function() {
    $('.switch input').on('change', function() {
      var isChecked = $(this).is(':checked');
      var state;
      var $switchLabel = $('.switch label');
      console.log('isChecked: ' + isChecked); 

      if(isChecked) {
        state = $switchLabel.attr('1');
      } else {
        state = $switchLabel.attr('0');
      }

      console.log('State: ' + state);

    });
  });

})();